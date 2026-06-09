const std = @import("std");
const OnlineManager = @import("online.zig").OnlineManager;
const Cache = @import("cache.zig").Cache;

pub const CashOnline = struct {
    allocator: std.mem.Allocator,
    online_manager: *OnlineManager,
    cache: *Cache,

    pub fn init(allocator: std.mem.Allocator, om: *OnlineManager, cache: *Cache) CashOnline {
        return .{
            .allocator = allocator,
            .online_manager = om,
            .cache = cache,
        };
    }

    pub fn syncNode(self: *CashOnline, nodeID: []const u8) !void {
        const addr = try self.online_manager.node_registry.get(nodeID) orelse return error.NodeNotFound;
        try self.cache.set(nodeID, addr);
    }

    pub fn isNodeCached(self: *CashOnline, nodeID: []const u8) bool {
        return self.cache.get(nodeID) != null;
    }
};

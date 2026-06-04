const std = @import("std");

pub const VideoMemoryCache = struct {
    allocator: std.mem.Allocator,
    frames: std.StringHashMap([]const u8),
    mutex: std.Thread.Mutex,

    pub fn init(allocator: std.mem.Allocator) VideoMemoryCache {
        return .{
            .allocator = allocator,
            .frames = std.StringHashMap([]const u8).init(allocator),
            .mutex = .{},
        };
    }

    pub fn storeFrame(self: *VideoMemoryCache, frameID: []const u8, data: []const u8) !void {
        self.mutex.lock();
        defer self.mutex.unlock();
        try self.frames.put(frameID, data);
    }

    pub fn fetchFrame(self: *VideoMemoryCache, frameID: []const u8) ?[]const u8 {
        self.mutex.lock();
        defer self.mutex.unlock();
        return self.frames.get(frameID);
    }

    pub fn deinit(self: *VideoMemoryCache) void {
        self.frames.deinit();
    }
};

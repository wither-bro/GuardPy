const std = @import("std");

pub const Cache = struct {
    allocator: std.mem.Allocator,
    data: std.StringHashMap([]const u8),
    mutex: std.Thread.Mutex,

    pub fn init(allocator: std.mem.Allocator) Cache {
        return .{
            .allocator = allocator,
            .data = std.StringHashMap([]const u8).init(allocator),
            .mutex = .{},
        };
    }

    pub fn set(self: *Cache, key: []const u8, value: []const u8) !void {
        self.mutex.lock();
        defer self.mutex.unlock();
        try self.data.put(key, value);
    }

    pub fn get(self: *Cache, key: []const u8) ?[]const u8 {
        self.mutex.lock();
        defer self.mutex.unlock();
        return self.data.get(key);
    }
};

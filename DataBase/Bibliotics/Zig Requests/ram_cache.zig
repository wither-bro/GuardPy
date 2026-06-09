const std = @import("std");

pub const RamCache = struct {
    allocator: std.mem.Allocator,
    storage: std.StringHashMap([]const u8),
    mutex: std.Thread.Mutex,

    pub fn init(allocator: std.mem.Allocator) RamCache {
        return .{
            .allocator = allocator,
            .storage = std.StringHashMap([]const u8).init(allocator),
            .mutex = .{},
        };
    }

    pub fn store(self: *RamCache, key: []const u8, value: []const u8) !void {
        self.mutex.lock();
        defer self.mutex.unlock();
        try self.storage.put(key, value);
    }

    pub fn fetch(self: *RamCache, key: []const u8) ?[]const u8 {
        self.mutex.lock();
        defer self.mutex.unlock();
        return self.storage.get(key);
    }

    pub fn deinit(self: *RamCache) void {
        self.storage.deinit();
    }
};

const std = @import("std");

pub const MemoryCache = struct {
    allocator: std.mem.Allocator,
    entries: std.StringHashMap([]const u8),
    mutex: std.Thread.Mutex,

    pub fn init(allocator: std.mem.Allocator) MemoryCache {
        return .{
            .allocator = allocator,
            .entries = std.StringHashMap([]const u8).init(allocator),
            .mutex = .{},
        };
    }

    pub fn write(self: *MemoryCache, key: []const u8, value: []const u8) !void {
        self.mutex.lock();
        defer self.mutex.unlock();
        try self.entries.put(key, value);
    }

    pub fn read(self: *MemoryCache, key: []const u8) ?[]const u8 {
        self.mutex.lock();
        defer self.mutex.unlock();
        return self.entries.get(key);
    }

    pub fn clear(self: *MemoryCache) void {
        self.mutex.lock();
        defer self.mutex.unlock();
        self.entries.clearAndFree();
    }

    pub fn deinit(self: *MemoryCache) void {
        self.entries.deinit();
    }
};

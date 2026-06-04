const std = @import("std");
const Cache = @import("cache.zig").Cache;

pub const SessionManager = struct {
    allocator: std.mem.Allocator,
    cache: *Cache,
    mutex: std.Thread.Mutex,

    pub fn init(allocator: std.mem.Allocator, cache: *Cache) SessionManager {
        return .{
            .allocator = allocator,
            .cache = cache,
            .mutex = .{},
        };
    }

    pub fn createSession(self: *SessionManager, userID: []const u8, token: []const u8) !void {
        self.mutex.lock();
        defer self.mutex.unlock();
        try self.cache.set(userID, token);
    }

    pub fn validateSession(self: *SessionManager, userID: []const u8) bool {
        self.mutex.lock();
        defer self.mutex.unlock();
        return self.cache.get(userID) != null;
    }
};

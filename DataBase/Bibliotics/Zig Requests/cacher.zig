const std = @import("std");
const Cache = @import("cache.zig").Cache;
const RamCache = @import("ram_cache.zig").RamCache;
const MemoryCache = @import("memory_cache.zig").MemoryCache;
const VideoMemoryCache = @import("video_memory_cache.zig").VideoMemoryCache;

pub const Cacher = struct {
    allocator: std.mem.Allocator,
    general_cache: *Cache,
    ram_cache: *RamCache,
    mem_cache: *MemoryCache,
    video_cache: *VideoMemoryCache,

    pub fn init(allocator: std.mem.Allocator, gc: *Cache, rc: *RamCache, mc: *MemoryCache, vc: *VideoMemoryCache) Cacher {
        return .{
            .allocator = allocator,
            .general_cache = gc,
            .ram_cache = rc,
            .mem_cache = mc,
            .video_cache = vc,
        };
    }

    pub fn cacheItem(self: *Cacher, kind: []const u8, key: []const u8, data: []const u8) !void {
        if (std.mem.eql(u8, kind, "general")) {
            try self.general_cache.set(key, data);
        } else if (std.mem.eql(u8, kind, "ram")) {
            try self.ram_cache.store(key, data);
        } else if (std.mem.eql(u8, kind, "mem")) {
            try self.mem_cache.write(key, data);
        } else if (std.mem.eql(u8, kind, "video")) {
            try self.video_cache.storeFrame(key, data);
        }
    }
};

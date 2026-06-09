const std = @import("std");

const Cache = @import("cache.zig").Cache;
const RamCache = @import("ram_cache.zig").RamCache;
const MemoryCache = @import("memory_cache.zig").MemoryCache;
const VideoMemoryCache = @import("video_memory_cache.zig").VideoMemoryCache;
const Cacher = @import("cacher.zig").Cacher;

pub const System = struct {
    general: Cache,
    ram: RamCache,
    mem: MemoryCache,
    video: VideoMemoryCache,
    cacher: Cacher,

    pub fn init(allocator: std.mem.Allocator) System {
        var general = Cache.init(allocator);
        var ram = RamCache.init(allocator);
        var mem = MemoryCache.init(allocator);
        var video = VideoMemoryCache.init(allocator);
        
        const cacher = Cacher.init(allocator, &general, &ram, &mem, &video);

        return .{
            .general = general,
            .ram = ram,
            .mem = mem,
            .video = video,
            .cacher = cacher,
        };
    }

    pub fn deinit(self: *System) void {
        self.ram.deinit();
        self.mem.deinit();
        self.video.deinit();
    }
};

const std = @import("std");
const Clearer = @import("clear.zig").Clearer;

pub const ClearCache = struct {
    clearer: Clearer,

    pub fn init(clearer: Clearer) ClearCache {
        return .{ .clearer = clearer };
    }

    pub fn wipeSpecific(self: *ClearCache, target: []const u8) void {
        if (std.mem.eql(u8, target, "ram")) {
            self.clearer.system.ram.clear();
        } else if (std.mem.eql(u8, target, "mem")) {
            self.clearer.system.mem.clear();
        } else if (std.mem.eql(u8, target, "video")) {
            self.clearer.system.video.frames.clearAndFree();
        }
    }
};

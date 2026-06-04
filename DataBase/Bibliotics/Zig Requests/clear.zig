const std = @import("std");
const System = @import("_init.zig").System;

pub const Clearer = struct {
    system: *System,

    pub fn init(system: *System) Clearer {
        return .{ .system = system };
    }

    pub fn purgeAll(self: *Clearer) void {
        self.system.ram.clear();
        self.system.mem.clear();
        self.system.video.frames.clearAndFree();
    }
};

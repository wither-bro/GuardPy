// Data Base/Bibliotics/Zig Requests/docker.zig
const std = @import("std");
const OnlineManager = @import("online.zig").OnlineManager;
const IDRegistry = @import("id.zig").IDRegistry;
const RootRegistry = @import("root.zig").RootRegistry;

pub const DockerLibrary = struct {
    allocator: std.mem.Allocator,
    online: OnlineManager,
    ids: IDRegistry,
    roots: RootRegistry,

    pub fn init(allocator: std.mem.Allocator) DockerLibrary {
        return .{
            .allocator = allocator,
            .online = OnlineManager.init(allocator),
            .ids = IDRegistry.init(allocator),
            .roots = RootRegistry.init(allocator),
        };
    }
};

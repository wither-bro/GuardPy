// Data Base/Bibliotics/Zig Requests/Clearing Tools/clear_utorution.zig
const std = @import("std");

pub const ClearUtorution = struct {
    auth_token: []const u8,

    pub fn init(token: []const u8) ClearUtorution {
        return .{
            .auth_token = token,
        };
    }

    pub fn reset(self: *ClearUtorution) void {
        std.debug.print("UTORUTION_RESET: Clearing auth context for token: {s}\n", .{self.auth_token});
    }
};

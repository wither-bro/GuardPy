// Data Base/Bibliotics/Zig Requests/Clearing Tools/clear_session.zig
const std = @import("std");

pub const ClearSession = struct {
    session_id: []const u8,

    pub fn init(session_id: []const u8) ClearSession {
        return .{
            .session_id = session_id,
        };
    }

    pub fn purge(self: *ClearSession) void {
        std.debug.print("SESSION_PURGE: Session {s} has been cleared.\n", .{self.session_id});
    }
};

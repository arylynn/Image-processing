{ pkgs }: {
	deps = [
		pkgs.gitlab-shell
  pkgs.run
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}
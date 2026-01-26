{
  description = "Astro site with Org-mode notes";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            nodejs_20
            emacs-nox
	    texlive.combined.scheme-full
	    texlab
	    tectonic
            nodePackages.npm
            pandoc
            python3
          ];

          shellHook = ''
            echo "Environment ready! Node $(node --version), Emacs $(emacs --version | head -n1)"
          '';
        };
      }
    );
}

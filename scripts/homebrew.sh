#!/bin/bash
# Get the latest release and populate a Homebrew formula with the release
# details

RELEASE_NAME=$(gh release view --json tagName | jq .tagName)
echo "Release name: $RELEASE_NAME"

# strip double quotes form release name
RELEASE_NAME=$(echo $RELEASE_NAME | tr -d '"')

gh release download $RELEASE_NAME -D release/assets --clobber

# ls release/assets | grep darwin
# nocol-darwin-aarch64.tar.gz
# nocol-darwin-x86_64.tar.gz
# shasum -a 256 yourfile.tar.gz
INTEL_HASH=$(shasum -a 256 release/assets/nocol-darwin-x86_64.tar.gz | awk '{print $1}')
ARM_HASH=$(shasum -a 256 release/assets/nocol-darwin-aarch64.tar.gz | awk '{print $1}')

cat scripts/nocol.rb | sed "s/{{tag}}/$RELEASE_NAME/g" \
	| sed "s/{{intel_hash}}/$INTEL_HASH/g" \
	| sed "s/{{arm_hash}}/$ARM_HASH/g" > ../homebrew-tap/nocol.rb

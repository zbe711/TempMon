#!/usr/bin/env bash
set -e

usage() {
    echo "Usage: $0 -l C99|Cpp"
    exit 1
}

LANG_CHOICE=""

while getopts "l:" opt; do
    case "$opt" in
        l)
            LANG_CHOICE="$OPTARG"
            ;;
        *)
            usage
            ;;
    esac
done

if [ -z "$LANG_CHOICE" ]; then
    usage
fi

case "$LANG_CHOICE" in
    C99)
        BUILD_LANG="C"
        TARGET_NAME="tempmon_c"
        ;;
    Cpp)
        BUILD_LANG="Cpp"
        TARGET_NAME="tempmon_cpp"
        ;;
    *)
        echo "Invalid language: $LANG_CHOICE"
        echo "Valid options are: C99, Cpp"
        # exit 1
        ;;
esac

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
echo "SCRIPT_DIR: $SCRIPT_DIR"
BUILD_DIR="$SCRIPT_DIR/build"

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake -DBUILD_LANG="$BUILD_LANG" ..
cmake --build . --target "$TARGET_NAME"

echo "Build finished. Run: $BUILD_DIR/$TARGET_NAME"


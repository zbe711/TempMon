#!/usr/bin/env bash
set -e

usage() {
    echo "Usage: $0 -l C99|Cpp"
    echo "   or: $0 docs"
    exit 1
}

# Check if first argument is "docs"
if [ "$1" = "docs" ]; then
    SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
    DOCS_DIR="$SCRIPT_DIR/docs"
    BUILD_DOCS_DIR="$SCRIPT_DIR/build/docs"
    
    # Check if sphinx-build is available
    if ! command -v sphinx-build >/dev/null 2>&1; then
        echo "Error: sphinx-build not found. Please install Sphinx:"
        echo "  pip install -r docs/requirements.txt"
        exit 1
    fi
    
    echo "Building documentation..."
    mkdir -p "$BUILD_DOCS_DIR"
    sphinx-build -b html "$DOCS_DIR" "$BUILD_DOCS_DIR"
    
    echo "Documentation build finished. Open: $BUILD_DOCS_DIR/index.html"
    exit 0
fi

# Original C/C++ build logic
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
        exit 1
        ;;
esac

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$SCRIPT_DIR/build"

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake -DBUILD_LANG="$BUILD_LANG" ..
cmake --build . --target "$TARGET_NAME"

echo "Build finished. Run: $BUILD_DIR/$TARGET_NAME"


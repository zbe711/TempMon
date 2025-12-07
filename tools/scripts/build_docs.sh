#!/usr/bin/env bash
set -e

# Get the script directory and project root
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"
DOCS_DIR="$PROJECT_ROOT/docs"
BUILD_DOCS_DIR="$PROJECT_ROOT/build/docs"

# Check if sphinx-build is available
if ! command -v sphinx-build >/dev/null 2>&1; then
    echo "Error: sphinx-build not found. Please install Sphinx:"
    echo "  pip install -r docs/requirements.txt"
    exit 1
fi

echo "Building documentation..."
echo "  Source: $DOCS_DIR"
echo "  Output: $BUILD_DOCS_DIR"

# Create build directory
mkdir -p "$BUILD_DOCS_DIR"

# Build documentation
sphinx-build -b html "$DOCS_DIR" "$BUILD_DOCS_DIR"

echo ""
echo "Documentation build finished. Open: $BUILD_DOCS_DIR/index.html"


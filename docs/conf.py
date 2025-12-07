import os
import sys
from datetime import datetime

project = "Temperature Monitoring Requirements"
author = "Zebbiche Badr Eddine"
year = datetime.now().year
copyright = f"{year}, {author}"

extensions = [
    "sphinx.ext.autodoc",
    "sphinx_needs",
]

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

html_theme = "sphinx_rtd_theme"

# Configure navigation depth
html_theme_options = {
    "navigation_depth": 4,
    "collapse_navigation": True,
}

needs_types = [
    {
        "directive": "req",
        "title": "Requirement",
        "prefix": "REQ_",
        "color": "#BFD8D2",
        "style": "node",
    },
]

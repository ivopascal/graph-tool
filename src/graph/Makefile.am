## Process this file with automake to produce Makefile.in

SUBDIRS = generation stats clustering community util misc centrality correlations

AM_CPPFLAGS =\
    -I$(srcdir)/.. \
    -I$(srcdir)/../boost-workaround \
    -DHAVE_CONFIG_H

AM_CXXFLAGS =\
    -Wall \
    $(PYTHON_CPPFLAGS) \
    $(BOOST_CPPFLAGS)

AM_CFLAGS=$(AM_CXXFLAGS)

libgraph_tool_coredir = $(pythondir)/graph_tool
libgraph_tool_core_LTLIBRARIES = libgraph_tool_core.la

libgraph_tool_core_la_SOURCES = \
    graph_bind.cc \
    graph.cc \
    graph_copy.cc \
    graph_filtering.cc \
    graph_io.cc \
    graph_properties.cc \
    graph_python_interface.cc \
    graph_python_interface_export.cc \
    graph_selectors.cc \
    graphml.cpp\
    read_graphviz_spirit.cpp\
    ../boost-workaround/boost/graph/filtered_graph.hpp\
    ../boost-workaround/boost/graph/graphml.hpp

libgraph_tool_core_la_includedir = $(pythondir)/graph_tool/include
libgraph_tool_core_la_include_HEADERS = \
    graph_adaptor.hh \
    graph_wrap.hh \
    graph_filtering.hh \
    graph.hh \
    graph_properties.hh \
    graph_python_interface.hh \
    graph_selectors.hh \
    graph_util.hh \
    histogram.hh \
    mpl_nested_loop.hh \
    shared_map.hh \
    fast_vector_property_map.hh \
    numpy_bind.hh \
    ../../config.h

libgraph_tool_core_la_LIBADD = $(MOD_LIBADD)
libgraph_tool_core_la_LDFLAGS = $(MOD_LDFLAGS)


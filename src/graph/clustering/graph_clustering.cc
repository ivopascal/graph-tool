// graph-tool -- a general graph modification and manipulation thingy
//
// Copyright (C) 2007  Tiago de Paula Peixoto <tiago@forked.de>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 3
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "graph_filtering.hh"

#include "graph.hh"
#include "graph_selectors.hh"
#include "graph_properties.hh"

#include "graph_clustering.hh"

#include <boost/python.hpp>

using namespace std;
using namespace boost;
using namespace boost::lambda;
using namespace graph_tool;

python::tuple global_clustering(GraphInterface& g)
{
    double c, c_err;
    bool directed = g.GetDirected();
    g.SetDirected(false);
    run_action<graph_tool::detail::never_directed>()
        (g, lambda::bind<void>(get_global_clustering(), lambda::_1,
                               lambda::var(c), lambda::var(c_err)))();
    g.SetDirected(directed);
    return python::make_tuple(c, c_err);
}

void local_clustering(GraphInterface& g, boost::any prop)
{
    bool directed = g.GetDirected();
    g.SetDirected(false);
    run_action<graph_tool::detail::never_directed>()
        (g, lambda::bind<void>(set_clustering_to_property(), lambda::_1,
                               lambda::_2),
         writable_vertex_scalar_properties())(prop);
    g.SetDirected(directed);
}

using namespace boost::python;

void extended_clustering(GraphInterface& g, python::list props);

BOOST_PYTHON_MODULE(libgraph_tool_clustering)
{
    def("global_clustering", &global_clustering);
    def("local_clustering", &local_clustering);
    def("extended_clustering", &extended_clustering);
}

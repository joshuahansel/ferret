/*
   This file is part of FERRET, an add-on module for MOOSE

   FERRET is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   For help with FERRET please contact J. Mangeri <john.m.mangeri@gmail.com>
   and be sure to track new changes at github.com/mangerij/ferret

**/

#include "SurfaceChargeP.h"

registerMooseObject("FerretApp", SurfaceChargeP);

InputParameters SurfaceChargeP::validParams()

{
  InputParameters params = AuxKernel::validParams();
  params += BoundaryRestrictableRequired::validParams();
  params.addClassDescription("Calculates P*n");
  params.addRequiredCoupledVar("polar_x", "The x component of the polarization");
  params.addRequiredCoupledVar("polar_y", "The y component of the polarization");
  params.addCoupledVar("polar_z", 0.0, "The z component of the polarization");
  return params;
}


SurfaceChargeP::SurfaceChargeP(const InputParameters & parameters) :
  AuxKernel(parameters),
   _normals(_assembly.normals()),
   _polar_x(coupledValue("polar_x")),
   _polar_y(coupledValue("polar_y")),
   _polar_z(coupledValue("polar_z"))
{
}

Real
SurfaceChargeP::computeValue()
{
    return _polar_x[_qp]*_normals[_qp](0) + _polar_y[_qp]*_normals[_qp](1) + _polar_z[_qp]*_normals[_qp](2);
}

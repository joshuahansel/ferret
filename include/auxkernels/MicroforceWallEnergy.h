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

#ifndef MICROFORCEWALLENERGY_H
#define MICROFORCEWALLENERGY_H

#include "AuxKernel.h"

class MicroforceWallEnergy : public AuxKernel
{
public:
  MicroforceWallEnergy(const InputParameters & parameters);

  static InputParameters validParams();

protected:
  virtual Real computeValue();
  const unsigned int _component;
  const VariableGradient & _polar_i_grad;
  const VariableGradient & _polar_j_grad;
  const VariableGradient & _polar_k_grad;
  const unsigned int _ii, _jj, _kk;
  const MaterialProperty<Real> & _G110;
  const MaterialProperty<Real> & _G11;
  const MaterialProperty<Real> & _G12;
  const MaterialProperty<Real> & _G44;
  const MaterialProperty<Real> & _G44P;
};

#endif // MICROFORCEWALLENERGY_H

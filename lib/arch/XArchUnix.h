/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2002 Chris Schoeneman
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file COPYING that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef XARCHUNIX_H
#define XARCHUNIX_H

#include "XArch.h"

//! Lazy error message string evaluation for unix
class XArchEvalUnix : public XArchEval {
public:
	XArchEvalUnix(int err) : m_errno(err) { }
	virtual ~XArchEvalUnix() { }

	// XArchEval overrides
	virtual XArchEval*	clone() const throw();
	virtual std::string	eval() const throw();

private:
	int					m_errno;
};

#endif

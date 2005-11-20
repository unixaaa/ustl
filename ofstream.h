// This file is part of the ustl library, an STL implementation.
//
// Copyright (C) 2005 by Mike Sharov <msharov@users.sourceforge.net>
// This file is free software, distributed under the MIT License.
//
// ofstream.h
//

#ifndef FDOSTREAM_H_5E27FC3D530BF3CA04D6C73F5700EECC
#define FDOSTREAM_H_5E27FC3D530BF3CA04D6C73F5700EECC

#include "sistream.h"
#include "sostream.h"
#include "fstream.h"

namespace ustl {

/// \class ofstream fdostream.h ustl.h
/// \ingroup DeviceStreams
/// \brief A string stream that writes to an fd. Implements cout and cerr.
class ofstream : public ostringstream {
public:
			ofstream (void);
    explicit		ofstream (int fd);
    explicit		ofstream (const char* filename, openmode mode = out);
    virtual	       ~ofstream (void);
    inline void		open (const char* filename, openmode mode = out) { m_File.open (filename, mode); clear (m_File.rdstate()); }
    inline void		close (void)		{ m_File.close(); clear (m_File.rdstate()); }
    inline bool		is_open (void) const	{ return (m_File.is_open()); }
    inline iostate	exceptions (iostate v)	{ ostringstream::exceptions(v); return (m_File.exceptions(v)); }
    inline void		setstate (iostate v)	{ ostringstream::setstate(v); m_File.setstate(v); }
    inline void		clear (iostate v = goodbit)	{ ostringstream::clear(v); m_File.clear(v); }
    void		flush (void);
    virtual size_type	overflow (size_type n = 1);
private:
    fstream		m_File;
};

/// \class ifstream fdostream.h ustl.h
/// \ingroup DeviceStreams
/// \brief A string stream that reads from an fd. Implements cin.
class ifstream : public istringstream {
public:
			ifstream (void);
    explicit		ifstream (int fd);
    explicit		ifstream (const char* filename, openmode mode = in);
    inline void		open (const char* filename, openmode mode = in)	{ m_File.open (filename, mode); clear (m_File.rdstate()); }
    inline void		close (void)		{ m_File.close(); clear (m_File.rdstate()); }
    inline bool		is_open (void) const	{ return (m_File.is_open()); }
    inline iostate	exceptions (iostate v)	{ istringstream::exceptions(v); return (m_File.exceptions(v)); }
    inline void		setstate (iostate v)	{ istringstream::setstate(v); m_File.setstate(v); }
    inline void		clear (iostate v = goodbit)	{ istringstream::clear(v); m_File.clear(v); }
    void		sync (void);
    virtual size_type	underflow (size_type n = 1);
private:
    string		m_Buffer;
    fstream		m_File;
};

extern ofstream cout, cerr;
extern ifstream cin;

} // namespace ustl

#endif


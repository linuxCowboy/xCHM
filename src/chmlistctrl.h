/*

  Copyright (C) 2003  Razvan Cojocaru <razvanco@gmx.net>
 
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/


#ifndef __CHMLISTCTRL_H_
#define __CHMLISTCTRL_H_

#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/string.h>


// Forward declarations.
class CHMHtmlWindow;


/*! 
  \class wxListCtrl
  \brief wxWindows list control class.
*/


//! List control class meant to emulate the look and feel of a wxListBox.
class CHMListCtrl : public wxListCtrl {

public:
	/*!
	  \brief Initializes the custom list control.
	  \param parent The parent widget.
	  \param html Pointer to a CHMHtmlWindow that I'll associate with
	  this object so that selecting an item from the list will display
	  the corresponding page in the HTML window.
	  \param id Widget id.
	 */
	CHMListCtrl(wxWindow *parent, CHMHtmlWindow *html,
		    wxWindowID id = -1);

public:
	//! Cleans up and removes all the list items.
	void Reset();

	/*!
	  \brief Adds an URL to the list. For every URL, you should
	  also add a title.
	  \param url The URL to add to the list.
	 */
	void AddUrl(const wxString& url) { _urls.Add(url); }

	/*!
	  \brief Adds a title to the list. The title is what you see as
	  a list item, and the URL is the hidden info used to locate the
	  page associated with the title. Again, at all times a title is
	  being added, an associated URL must also be added.
	  \param title The title to add.
	 */
	void AddTitle(const wxString& title);
	
	//! Loads the page that corresponds to the item currently selected.
	void LoadSelected();

	//! Should be called every time after all the elements have been added.
	void UpdateUI();

protected:
	//! Gets called when the widget is being resized.
	void OnSize(wxSizeEvent& event);
	
	//! Implements functionality for the virtual wxWindows list control.
	wxString OnGetItemText(long item, long column) const;

private:
	wxArrayString _titles;
	wxArrayString _urls;
	CHMHtmlWindow *_html;

private:
	DECLARE_EVENT_TABLE()
};


#endif // __CHMLISTCTRL_H_

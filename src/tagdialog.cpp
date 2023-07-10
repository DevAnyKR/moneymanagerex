/*******************************************************
 Copyright (C) 2006 Madhan Kanagavel
 Copyright (C) 2015 Gabriele-V
 Copyright (C) 2022  Mark Whalley (mark@ipx.co.uk)

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
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ********************************************************/

#include "tagdialog.h"
#include "constants.h"
#include "paths.h"
#include "util.h"
#include "model/Model_Tag.h"

wxIMPLEMENT_DYNAMIC_CLASS(mmTagDialog, wxDialog);

wxBEGIN_EVENT_TABLE(mmTagDialog, wxDialog)
EVT_BUTTON(wxID_ADD, mmTagDialog::OnAdd)
EVT_BUTTON(wxID_EDIT, mmTagDialog::OnEdit)
EVT_BUTTON(wxID_REMOVE, mmTagDialog::OnDelete)
EVT_TEXT(wxID_FIND, mmTagDialog::OnTextChanged)
EVT_LISTBOX(wxID_VIEW_LIST, mmTagDialog::OnListSelChanged)
EVT_CHECKLISTBOX(wxID_VIEW_LIST, mmTagDialog::OnCheckboxSelChanged)
EVT_BUTTON(wxID_OK, mmTagDialog::OnOk)
EVT_BUTTON(wxID_CANCEL, mmTagDialog::OnCancel)
wxEND_EVENT_TABLE()

mmTagDialog::mmTagDialog() : isSelection_(false)
{
}

mmTagDialog::~mmTagDialog()
{
}

mmTagDialog::mmTagDialog(wxWindow* parent, bool isSelection, const wxArrayString& selectedTags) : isSelection_(isSelection), selectedTags_(selectedTags)
{
    this->SetFont(parent->GetFont());
    Create(parent);
    if (isSelection_)
    {
        for (const auto& tag : selectedTags)
        {
            int index = tagCheckListBox_->FindString(tag);
            if (index != wxNOT_FOUND)
                tagCheckListBox_->Check(index);
        }
    }

    SetMinSize(wxSize(300, 420));
    Fit();
}

bool mmTagDialog::Create(wxWindow* parent, wxWindowID id
    , const wxString& caption, const wxString& name
    , const wxPoint& pos, const wxSize& size, long style)
{
    SetExtraStyle(GetExtraStyle() | wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create(parent, id, caption, pos, size, style, name);

    SetEvtHandlerEnabled(false);

    CreateControls();

    SetEvtHandlerEnabled(true);

    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    this->SetInitialSize();
    SetIcon(mmex::getProgramIcon());

    Fit();
    Centre();
    return TRUE;
}

void mmTagDialog::CreateControls()
{
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBox* sb = new wxStaticBox(this, wxID_STATIC, _("Current Tags"));
    wxStaticBoxSizer* itemBoxSizer2 = new wxStaticBoxSizer(sb, wxVERTICAL);
    boxSizer->Add(itemBoxSizer2, g_flagsExpand);
    this->SetSizer(boxSizer);

    //--------------------------
    for (const auto& tag : Model_Tag::instance().all(DB_Table_TAG_V1::COL_TAGNAME))
        tagList_.Add(tag.TAGNAME);

    if (!isSelection_)
    {
        tagListBox_ = new wxListBox(sb, wxID_VIEW_LIST, wxDefaultPosition, wxDefaultSize, tagList_, wxLB_EXTENDED | wxLB_SORT);
        itemBoxSizer2->Add(tagListBox_, g_flagsExpand);
    }
    else
    {
        tagCheckListBox_ = new wxCheckListBox(sb, wxID_VIEW_LIST, wxDefaultPosition, wxDefaultSize, tagList_, wxLB_EXTENDED | wxLB_SORT);
        itemBoxSizer2->Add(tagCheckListBox_, g_flagsExpand);
    }

    wxPanel* searchPanel = new wxPanel(this, wxID_ANY);
    itemBoxSizer2->Add(searchPanel, wxSizerFlags(g_flagsExpand).Proportion(0));
    wxBoxSizer* search_sizer = new wxBoxSizer(wxHORIZONTAL);
    searchPanel->SetSizer(search_sizer);

    searchCtrl_ = new wxSearchCtrl(searchPanel, wxID_FIND);
    search_sizer->Add(new wxStaticText(searchPanel, wxID_STATIC, _("Search")), g_flagsH);
    search_sizer->Add(searchCtrl_, g_flagsExpand);

    wxPanel* buttonsPanel = new wxPanel(this, wxID_ANY);
    itemBoxSizer2->Add(buttonsPanel, wxSizerFlags(g_flagsV).Center());
    wxBoxSizer* buttonsSizer = new wxBoxSizer(wxVERTICAL);
    buttonsPanel->SetSizer(buttonsSizer);

    wxStdDialogButtonSizer* editButtonSizer = new wxStdDialogButtonSizer;
    buttonsSizer->Add(editButtonSizer, wxSizerFlags(g_flagsV).Border(wxALL, 0).Center());

    buttonAdd_ = new wxButton(buttonsPanel, wxID_ADD, _("&Add "));
    editButtonSizer->Add(buttonAdd_, g_flagsH);
    mmToolTip(buttonAdd_, _("Add a new tag"));

    buttonEdit_ = new wxButton(buttonsPanel, wxID_EDIT, _("&Edit "));
    editButtonSizer->Add(buttonEdit_, g_flagsH);
    buttonEdit_->Enable(false);
    mmToolTip(buttonEdit_, _("Edit the name of an existing tag"));

    buttonDelete_ = new wxButton(buttonsPanel, wxID_REMOVE, _("&Delete "));
    editButtonSizer->Add(buttonDelete_, g_flagsH);
    buttonDelete_->Enable(false);
    mmToolTip(buttonDelete_, _("Delete an existing tag. The tag cannot be used by existing transactions."));

    //--------------------------
    wxStdDialogButtonSizer* dlgButtonSizer = new wxStdDialogButtonSizer();
    itemBoxSizer2->Add(dlgButtonSizer, wxSizerFlags(g_flagsV).Centre());

    wxButton* itemButton24 = new wxButton(this, wxID_OK, (isSelection_ ? _("Select") : _("&OK ")));
    dlgButtonSizer->Add(itemButton24, g_flagsH);
    mmToolTip(itemButton24, (isSelection_ ? _("Use the currently selected tags for the transaction") : _("Save any changes made")));

    wxButton* itemButton25 = new wxButton(this, wxID_CANCEL, wxGetTranslation(g_CloseLabel));
    dlgButtonSizer->Add(itemButton25, g_flagsH);
    mmToolTip(itemButton25, _("Any changes will be lost without update"));
}

void mmTagDialog::fillControls()
{
    wxArrayString filteredList;
    for (const auto& tag : tagList_)
        if (tag.Lower().Matches(mask_string_ + "*"))
            filteredList.Add(tag);

    if (isSelection_)
    {
        tagCheckListBox_->Set(filteredList);
        // reselect previously selected items
        for (const auto& tag : selectedTags_)
        {
            int index = tagCheckListBox_->FindString(tag);
            if (index != wxNOT_FOUND)
                tagCheckListBox_->Check(index);
        }
    }
    else
    {
        tagListBox_->Set(filteredList);
    }
}

bool mmTagDialog::validateName(const wxString& name)
{
    if (name.Find(' ') != wxNOT_FOUND)
    {
        wxString errMsg = _("Name contains tag delimiter");
        errMsg << "\n\n" << _("Tag names may not contain the space (' ') character");
        wxMessageBox(errMsg, _("Organize Tags: Invalid Name"), wxOK | wxICON_ERROR);
        return false;
    }

    if (name == "&" || name == "|")
    {
        wxString errMsg = _("Invalid tag name");
        errMsg << "\n\n" << _("Tag names may not be the single characters '&' or '|' which are restricted for filter operators");
        wxMessageBox(errMsg, _("Organize Tags: Invalid Name"), wxOK | wxICON_ERROR);
        return false;
    }

    return true;
    
}

void mmTagDialog::OnOk(wxCommandEvent& WXUNUSED(event))
{
    EndModal(wxID_OK);
}

void mmTagDialog::OnCancel(wxCommandEvent& WXUNUSED(event))
{
    EndModal(wxID_CANCEL);
}

void mmTagDialog::OnAdd(wxCommandEvent& WXUNUSED(event))
{
    wxString prompt_msg = _("Enter the name for the new tag:");
    const wxString& text = wxGetTextFromUser(prompt_msg, _("Add Tag"), "");
    if (text.IsEmpty() || !validateName(text))
        return;

    const auto& tags = Model_Tag::instance().find(Model_Tag::TAGNAME(text));
    if (!tags.empty())
    {
        wxMessageBox(_("A tag with this name exists"), _("Organize Tags: Adding Error"), wxOK | wxICON_ERROR);
        return;
    }

    Model_Tag::Data* tag = Model_Tag::instance().create();
    tag->TAGNAME = text;
    tag->ACTIVE = 1;
    Model_Tag::instance().save(tag);
    refreshRequested_ = true;
    tagList_.Add(text);
    fillControls();
}

void mmTagDialog::OnEdit(wxCommandEvent& WXUNUSED(event))
{
    wxArrayInt selections;
    wxString old_name;
    if (isSelection_)
    {
        tagCheckListBox_->GetSelections(selections);
        old_name = tagCheckListBox_->GetString(selections[0]);
    }
    else
    {
        tagListBox_->GetSelections(selections);
        old_name = tagListBox_->GetString(selections[0]);
    }

    const wxString msg = wxString::Format(_("Enter a new name for '%s'"), old_name);
    wxString text = wxGetTextFromUser(msg, _("Edit Tag"), old_name);

    if (text.IsEmpty() || old_name == text || !validateName(text))
        return;

    Model_Tag::Data* tag = Model_Tag::instance().get(text);
    if (tag)
    {
        wxString errMsg = _("A tag with this name exists");
        wxMessageBox(errMsg, _("Organize Tags: Editing Error"), wxOK | wxICON_ERROR);
        return;
    }

    tag = Model_Tag::instance().get(old_name);
    tag->TAGNAME = text;
    Model_Tag::instance().save(tag);
    tagList_.Remove(old_name);
    tagList_.Add(text);
    int index = selectedTags_.Index(old_name);
    if (index != wxNOT_FOUND)
    {
        selectedTags_.RemoveAt(index);
        selectedTags_.Add(text);
    }
    refreshRequested_ = true;
    fillControls();
}

void mmTagDialog::OnDelete(wxCommandEvent& WXUNUSED(event))
{
    wxArrayInt selections;
    wxArrayString stringSelections;
    if (isSelection_)
    {
        tagCheckListBox_->GetSelections(selections);
        for (const auto& selection : selections)
            stringSelections.Add(tagCheckListBox_->GetString(selection));
    }
    else
    {
        tagListBox_->GetSelections(selections);
        for (const auto& selection : selections)
            stringSelections.Add(tagListBox_->GetString(selection));
    }

    if (stringSelections.IsEmpty())
        return;

    Model_Tag::instance().Savepoint();
    Model_Taglink::instance().Savepoint();
    Model_Checking::instance().Savepoint();
    Model_Splittransaction::instance().Savepoint();
    for (const auto& selection : stringSelections)
    {
        Model_Tag::Data* tag = Model_Tag::instance().get(selection);
        int tag_used = Model_Tag::instance().is_used(tag->TAGID);
        if (tag_used == 1)
        {
            wxMessageBox(wxString::Format(_("Tag '%s' in use"), tag->TAGNAME), _("Organize Tags: Delete Error"), wxOK | wxICON_ERROR);
            continue;
        }
        wxMessageDialog msgDlg(this, wxString::Format(_("Deleted transactions exist which use tag '%s'."), tag->TAGNAME)
                + "\n\n" + _("Deleting the tag will also automatically purge the associated deleted transactions.")
                + "\n\n" + _("Do you wish to continue ?")
                , _("Confirm Tag Deletion"), wxYES_NO | wxNO_DEFAULT | wxICON_WARNING);
        
        if (tag_used == 0 || (tag_used == -1 && msgDlg.ShowModal() == wxID_YES))
        {
            Model_Taglink::Data_Set taglinks = Model_Taglink::instance().find(Model_Taglink::TAGID(tag->TAGID));
            for (const auto& link : taglinks)
                if (link.REFTYPE == Model_Attachment::reftype_desc(Model_Attachment::TRANSACTION))
                    // Removing the checking record also deletes the taglinks
                    Model_Checking::instance().remove(link.REFID);
                else if (link.REFTYPE == Model_Attachment::reftype_desc(Model_Attachment::TRANSACTIONSPLIT))
                    Model_Checking::instance().remove(Model_Splittransaction::instance().get(link.REFID)->TRANSID);
            Model_Tag::instance().remove(tag->TAGID);
            tagList_.Remove(selection);
            int index = selectedTags_.Index(selection);
            if (index != wxNOT_FOUND)
                selectedTags_.RemoveAt(index);
        }
    }
    Model_Tag::instance().ReleaseSavepoint();
    Model_Taglink::instance().ReleaseSavepoint();
    Model_Checking::instance().ReleaseSavepoint();
    Model_Splittransaction::instance().ReleaseSavepoint();
    refreshRequested_ = true;
    fillControls();
}

void mmTagDialog::OnTextChanged(wxCommandEvent& event)
{
    mask_string_ = event.GetString();
    if (!mask_string_.IsEmpty())
        mask_string_ = mask_string_.Lower().Prepend("*");
    fillControls();
    searchCtrl_->SetFocus();
    searchCtrl_->SetInsertionPointEnd();
}

void mmTagDialog::OnListSelChanged(wxCommandEvent& WXUNUSED(event))
{
    buttonEdit_->Enable(false);
    buttonDelete_->Enable(false);

    wxArrayInt selections;
    wxArrayString stringSelections;
    if (isSelection_)
    {
        tagCheckListBox_->GetSelections(selections);
        for (const auto& selection : selections)
            stringSelections.Add(tagCheckListBox_->GetString(selection));
    }
    else
    {
        tagListBox_->GetSelections(selections);
        for (const auto& selection : selections)
            stringSelections.Add(tagListBox_->GetString(selection));
    }

    int count = selections.GetCount();

    // Can only edit one tag at a time
    if (count == 1)
    {
        buttonEdit_->Enable();
    }
    // Can delete multiple tags at once as long as all are unused
    if (count > 0)
    {
        bool is_used = false;
        for (const auto& selection : stringSelections)
        {
            Model_Tag::Data* tag = Model_Tag::instance().get(selection);
            is_used |= Model_Tag::instance().is_used(tag->TAGID) == 1;
        }
        buttonDelete_->Enable(!is_used);
    }    
}

void mmTagDialog::OnCheckboxSelChanged(wxCommandEvent& event)
{
    if (tagCheckListBox_->IsChecked(event.GetSelection()))
        selectedTags_.Add(event.GetString());
        else
        {
            int index = selectedTags_.Index(event.GetString());
            if (index != wxNOT_FOUND)
                selectedTags_.RemoveAt(index);
        }
    
}
#pragma once



// CThundagaEditor
class CThundagaEditor : public CPropertySheet
{
	DECLARE_DYNAMIC(CThundagaEditor)

public:
	CThundagaEditor();
	virtual BOOL CThundagaEditor::OnInitDialog();
	CThundagaEditor(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CThundagaEditor();

protected:
	DECLARE_MESSAGE_MAP()
};



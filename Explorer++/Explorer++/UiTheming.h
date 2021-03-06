// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include "Explorer++_internal.h"
#include "Tab.h"
#include "TabContainerInterface.h"
#include <boost/signals2.hpp>

class UiTheming
{
public:

	UiTheming(IExplorerplusplus *expp, TabContainerInterface *tabContainer);
	~UiTheming();

	bool SetListViewColors(COLORREF backgroundColor, COLORREF textColor);
	void SetTreeViewColors(COLORREF backgroundColor, COLORREF textColor);

private:

	void OnTabCreated(int tabId, BOOL switchToNewTab);

	bool ApplyListViewColorsForAllTabs(COLORREF backgroundColor, COLORREF textColor);
	bool ApplyListViewColorsForTab(const Tab &tab, COLORREF backgroundColor, COLORREF textColor);

	IExplorerplusplus *m_expp;
	TabContainerInterface *m_tabContainer;

	boost::signals2::connection m_tabCreatedConnection;

	bool m_customListViewColorsApplied;
	COLORREF m_listViewBackgroundColor;
	COLORREF m_listViewTextColor;
};
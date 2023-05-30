import browser from 'webextension-polyfill';
import { isDev } from '../shared/utils';

// show welcome page on new install
browser.runtime.onInstalled.addListener(async (details) => {
  if (details.reason === 'install') {
    //show the welcome page
    const url = browser.runtime.getURL(isDev ? 'src/welcome/welcome.html' : 'welcome.html'); // TODO: better approach
    await browser.tabs.create({ url });
  }
  chrome.contextMenus.create({
    id: 'translation',
    title: '選択したテキストを翻訳',
    contexts: ['selection'],
  });
});

chrome.contextMenus.onClicked.addListener(async (info, tab) => {
    if (tab !== undefined) {
      switch (info.menuItemId) {
        case 'translation':
            const selectedText = info.selectionText !== undefined ? info.selectionText : '';
             chrome.tabs.sendMessage(tab.id as number, {
               type: 'SHOW',
               data: {
                 originalText: selectedText,
               },
             });
          break;
      }
    }
  });

  chrome.runtime.onMessage.addListener(async function (message, sender, sendResponse) {
    if (message.type === 'TRANSLATE') {
      const selectedText = message.data.selectionText ?? '';
      chrome.tabs.sendMessage(sender.tab?.id as number, {
        type: 'SHOW',
        data: {
          originalText: selectedText,
        },
      });
    }
  });

export {};

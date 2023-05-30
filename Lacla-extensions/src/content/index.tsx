import React from 'react';
import { createRoot } from 'react-dom/client';
import Content from './Content';

const Main = ({ orect, originalText }: { orect: DOMRect; originalText: string; }) => {
    return (
        <div
            style={{
                position: 'absolute',
                width: '100%',
                left: '0px',
                top: '0px',
                zIndex: 2147483550,
            }}
        >
            <div
                style={{
                    position: 'absolute',
                    left: window.scrollX + orect.left, // 自由に変えて良い
                    top: window.scrollY + orect.bottom + 10, // 自由に変えて良い
                    zIndex: 2147483550,
                    backgroundColor: 'white',
                    border: '1px solid black',
                }}
            >
                <Content originalText={originalText} />
            </div>
        </div>
    );
};

const Icon = ({ selectedText, orect }: { selectedText: string; orect: DOMRect }) => {
    const handleClick = async () => {
        for (let i = 0; i < document.getElementsByTagName('my-extension-root-icon').length; i++) {
          document.getElementsByTagName('my-extension-root-icon')[i].remove();
        }
        chrome.runtime.sendMessage({
          type: 'TRANSLATE',
          data: {
            selectionText: selectedText,
          },
        });
      };
    return (
        <div
            style={{
                position: 'absolute',
                width: '100%',
                left: '0px',
                top: '0px',
                zIndex: 2147483550,
            }}
        >
            <div
                style={{
                    position: 'absolute',
                    left: window.scrollX + orect.right,
                    top: window.scrollY + orect.bottom,
                    zIndex: 2147483550,
                    backgroundColor: 'white',
                }}
            >
                <h1>ICONだよ</h1>
            </div>
        </div>
    );
};

chrome.runtime.onMessage.addListener(async function (message, sender, sendResponse) {
    const selection = window.getSelection();
    if (selection !== undefined && selection !== null && selection.toString() !== undefined) {
        const oRange = selection.getRangeAt(0);
        const oRect = oRange.getBoundingClientRect();
        if (selection.toString().length === 0) {
            return;
        }
        if (message.type === 'SHOW') {
            if (document.getElementsByTagName('my-extension-root').length > 0) {
                document.getElementsByTagName('my-extension-root')[0].remove();
            }
            const container = document.createElement('my-extension-root');
            document.body.after(container);
            createRoot(container).render(
                <Main
                    orect={oRect}
                    originalText={message.data.originalText.toString()}
                />
            );
        }
    }
});

document.addEventListener('mouseup', () => {
    const selection = window.getSelection();
    if (selection === undefined || selection === null) {
        return;
    }
    if (selection.toString().length > 0) {
        const oRange = selection.getRangeAt(0);
        const oRect = oRange.getBoundingClientRect();
        if (document.getElementsByTagName('my-extension-root-icon').length > 0) {
            return;
        }
        for (let i = 0; i < document.getElementsByTagName('my-extension-root').length; i++) {
            document.getElementsByTagName('my-extension-root')[i].remove();
        }
        const container = document.createElement('my-extension-root-icon');
        document.body.after(container);
        createRoot(container).render(<Icon selectedText={selection.toString()} orect={oRect} />);
    }
});

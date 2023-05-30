import React from 'react';
import { createRoot } from 'react-dom/client';

import Content from './Content';

const Main = ({ translatedText, originalText }: { translatedText: string; originalText: string; targetLang: string }) => {
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
          left: '10px', // 自由に変えて良い
          top: '10px', // 自由に変えて良い
          zIndex: 2147483550,
        }}
      >
        <Content />
      </div>
    </div>
  );
};

const container = document.createElement('my-extension-root');
document.body.after(container);
createRoot(container).render(
  <Main translatedText={'ここに翻訳したテキストが入る'} originalText={'ここに翻訳前のテキストが入る'} targetLang={'JA'} />
);
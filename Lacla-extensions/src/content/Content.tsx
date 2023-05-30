import React, { ReactElement } from 'react';

const Content = ({ originalText }: { originalText: string }): ReactElement => {
    return (
        <div>
            <h1>test</h1>
            <p>{originalText}</p>
        </div>
    );
};

export default Content;

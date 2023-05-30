import React from 'react';
import { render, screen } from '@testing-library/react';


import Content from './Content';

describe('content', () => {
  test('renders content example', () => {
    render(
        <Content originalText='Original Text' />
    );
    expect(screen.getByText('Content Example')).toBeInTheDocument();
  });
});

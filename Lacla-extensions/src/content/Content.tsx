import React, { useState, ReactElement, useEffect } from 'react';
import { MdDone, MdOutlineContentCopy, MdVolumeUp } from 'react-icons/md';
import { ActionIcon, Avatar, Box, CopyButton, Divider, Flex, Group, Select, Stack, Text, Tooltip } from '@mantine/core';
import { useClickOutside } from '@mantine/hooks';
import { original } from '@reduxjs/toolkit';

const Content = ({ originalText }: { originalText: string }): ReactElement => {
    const [opened, setOpened] = useState(true);
    const [diaglog, setDialog] = useState<HTMLDivElement | null>(null);
    const [translatedText, setTranslatedText] = useState<string>('');
    // 1.
    useClickOutside(() => setOpened(false), null, [diaglog]);
    // 2.
    const IconUrl = chrome.runtime.getURL('images/extension_128.png');
    useEffect(() => {
        async function getTranslatedText() {
            let data = { text: originalText };
            const API_URL = 'https://langclarify.herokuapp.com/gpt3dot5';
            let ansText = '(';
            const response = await fetch(API_URL, {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify(data),
            }).catch((error) => { console.error('Error:', error); });
            // eslint-disable-next-line @typescript-eslint/ban-ts-comment
            // @ts-ignore
            const reader = response.body.getReader();

            async function readStream(): Promise<any> {
                const { done, value } = await reader.read();

                if (done) {
                    console.log('ストリームの終了');
                    return ansText;
                }

                // 受信したデータの処理
                const chunk = new TextDecoder().decode(value);
                console.log('受信データ:', chunk);

                if (ansText !== undefined) {
                    ansText = ansText + chunk;
                    setTranslatedText(ansText);
                    if (ansText === '((') {
                        ansText = '(';
                    }
                }

                // 次のデータを読み込む
                return readStream();
            }
            // ストリームの読み込みを開始
            readStream();
        }
        getTranslatedText();
    }, []);

    return opened ? (
        <Box
            sx={(theme) => ({
                backgroundColor: 'white',
                textAlign: 'left',
                padding: theme.spacing.md,
                borderRadius: theme.radius.md,
                maxWidth: 400,
                boxShadow: '0 0 10px rgba(0,0,0,.3);',
                zIndex: 2147483550,
            })}
            component="div"
            ref={setDialog}
        >
            <Flex pb="xs" gap="xs" justify="flex-start" align="center">
                <Avatar src={IconUrl} />
                <Text size="md">訳文：</Text>
            </Flex>
            <Divider />
            <Stack pt="sm" spacing="xs" style={{ textAlign: 'left' }}>
                <Text size="sm">{translatedText}</Text>
                <Group position="right" spacing="xs">
                    {/* 3. */}
                    <Tooltip label="音声読み上げ" withArrow>
                        <ActionIcon>
                            <MdVolumeUp />
                        </ActionIcon>
                    </Tooltip>
                    {/* 4. */}
                    <CopyButton value={translatedText}>
                        {({ copied, copy }) => (
                            <Tooltip label={copied ? '訳文をコピーしました' : 'クリップボードにコピー'} withArrow>
                                <ActionIcon onClick={copy}>
                                    {copied ? <MdDone /> : <MdOutlineContentCopy />}
                                </ActionIcon>
                            </Tooltip>
                        )}
                    </CopyButton>
                </Group>
            </Stack>
        </Box>
    ) : (<></>)
};

export default Content;

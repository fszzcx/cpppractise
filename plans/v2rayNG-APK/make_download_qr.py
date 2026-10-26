# -*- coding: utf-8 -*-
"""生成手机下载 APK 用的二维码（局域网地址，手机连电脑热点后扫码即可下载）"""
import qrcode
from qrcode.image.styledpil import StyledPilImage
from qrcode.image.styles.colormasks import SolidFillColorMask
from PIL import Image, ImageDraw, ImageFont
import os

BASE = r'D:\WorkBuddy\plans\v2rayNG-APK'
GW = '192.168.137.1'
PORT = 8000

items = [
    ('手机下载 v2rayNG', 'http://%s:%d/v2rayNG.apk' % (GW, PORT),
     '扫这个码 → 直接用手机浏览器下载 APK'),
]

imgs = []
for title, url, desc in items:
    qr = qrcode.QRCode(version=None, error_correction=qrcode.constants.ERROR_CORRECT_M,
                       box_size=10, border=2)
    qr.add_data(url)
    qr.make(fit=True)
    img = qr.make_image(fill_color='#1a1a1a', back_color='#ffffff').convert('RGB')
    imgs.append((img, title, url, desc))

# 拼接成一张带说明的图
pad = 40
w = max(max(i[0].width for i in imgs) + pad * 2, 500)
h = sum(i[0].height + 150 for i in imgs) + pad

canvas = Image.new('RGB', (w, h), '#ffffff')
d = ImageDraw.Draw(canvas)

# 尝试加载中文字体
font_paths = [r'C:\Windows\Fonts\msyh.ttc', r'C:\Windows\Fonts\msyhbd.ttc',
              r'C:\Windows\Fonts\simhei.ttf', r'C:\Windows\Fonts\simsun.ttc']
def load(sz):
    for p in font_paths:
        if os.path.exists(p):
            try:
                return ImageFont.truetype(p, sz)
            except Exception:
                pass
    return ImageFont.load_default()

f_title = load(30)
f_url = load(20)
f_desc = load(20)

y = pad
for img, title, url, desc in imgs:
    d.text((pad, y), title, font=f_title, fill='#111111')
    y += 50
    canvas.paste(img, (pad, y))
    y += img.height + 12
    d.text((pad, y), url, font=f_url, fill='#0b5ed7')
    y += 34
    d.text((pad, y), desc, font=f_desc, fill='#555555')
    y += 64

out = os.path.join(BASE, '手机扫码下载APK.png')
canvas.save(out)
print('已生成:', out)
print('尺寸:', canvas.size)
print('二维码内容:', items[0][1])

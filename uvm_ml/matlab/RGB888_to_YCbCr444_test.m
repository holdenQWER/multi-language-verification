
close all;
clear
%run('RGB888_to_YCbCr444_confg.m);

I=(imread('./Scart.jpg'));
subplot(221);imshow(I);title('RGB Image');

R_i=double(I(:,:,1));
G_i=double(I(:,:,2));
B_i=double(I(:,:,3));


RGB2YCbCr_cfg_struct.height = 480;
RGB2YCbCr_cfg_struct.width = 640;

[Y_o,Cb_o,Cr_o]=RGB888_to_YCbCr444(R_i,G_i,B_i,RGB2YCbCr_cfg_struct);

I_o=uint8(cat(3,Y_o,Cb_o,Cr_o));

subplot(222); imshow(I_o(:,:,1)); title('Y Channel');
subplot(223); imshow(I_o(:,:,2)); title('Cb Channel');
subplot(224); imshow(I_o(:,:,3)); title('Cr Channel');

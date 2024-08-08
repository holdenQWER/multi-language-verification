% add bypass 
function [Y_o,Cb_o,Cr_o]=RGB888_to_YCbCr444(R_i,G_i,B_i,cfg_struct)

   %[height,width] = size(R_i);
   height = cfg_struct.height;
   width  = cfg_struct.width;


   img_o = zeros(height,width,3);
   img_i = double(cat(3,R_i,G_i,B_i));

   for i = 1 : height
      for j= 1 : width
         img_o(i,j,1) = bitshift(( img_i(i,j,1)*76 + img_i(i,j,2)*150 + img_i(i,j,3)*29),-8);
         img_o(i,j,2) = bitshift((-img_i(i,j,1)*43 - img_i(i,j,2)*84 + img_i(i,j,3)*128 + 32768),-8);
         img_o(i,j,3) = bitshift(( img_i(i,j,1)*128 - img_i(i,j,2)*107 - img_i(i,j,3)*20 + 32768),-8);
      end
   end
   Y_o  = img_o(:,:,1);
   Cb_o = img_o(:,:,2);
   Cr_o = img_o(:,:,3);
end

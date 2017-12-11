function feature = getfeature(I)
% Input: Normalized image of iris
% Output: Binary Vector - feature vector

% Uses 3 level Wavelet Decomposition
[CA,d,g,t] = dwt2(I,'db1') ;
[CD,y,u,p] = dwt2(CA,'db1') ;
[CA,d,g,t] = dwt2(CD,'db1') ;
[CT,CH,CV,CD] = dwt2(CA,'db1') ;
[r,c] = size(CH);
lh = reshape(CH,r*c,1);
hl = reshape(CV,r*c,1);
feature = [lh; hl];
for i=1:numel(feature)
    if(feature(i)>0)
        feature(i) = 1;
    else
        feature(i) = 0;
    end
end
end
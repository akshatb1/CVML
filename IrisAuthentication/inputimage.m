function score = inputimage(I1,I2)

% Input: 2 images (uint8 format)
% Output: Hamming Distance

%% First Image - Get Feature
[ci cp o] = thresh(I1,50,400); % segment eye image into pupil and iris regions
I1 = im2double((I1));
[polar_array, polar_noise] = normaliseiris(I1, ci(2), ci(1), ci(3),cp(2), cp(1), cp(3), 64, 512);
feature1 = getfeature(polar_array);

%% Second Image - Get Feature
[ci cp o] = thresh(I2,50,400); % segment eye image into pupil and iris regions
I2 = im2double((I2));
[polar_array, polar_noise] = normaliseiris(I2, ci(2), ci(1), ci(3),cp(2), cp(1), cp(3), 64, 512);
feature2 = getfeature(polar_array);

%% Hamming Distance
score = match(feature1, feature2);
end

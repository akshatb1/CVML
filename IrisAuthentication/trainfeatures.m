function feature = trainfeatures(I)
%% Segmentation
[ci cp o] = thresh(I,50,400); % segment eye image into pupil and iris regions
I = im2double((I));
%% Normalize Iris
[polar_array, polar_noise] = normaliseiris(I, ci(2), ci(1), ci(3),cp(2), cp(1), cp(3), 64, 512);
feature = getfeature(polar_array);
end
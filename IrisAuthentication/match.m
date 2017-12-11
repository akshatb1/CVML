function score = match(X,Y)
% Input: Two binary vectors
% Output: Hamming Distance
score = (sum(abs(X-Y)))/numel(X); % Using XOR
end
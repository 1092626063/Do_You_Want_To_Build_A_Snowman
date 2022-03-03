# A ConvNet for the 2020s

## Some important sentences
### Introduction
The biggest challenge is ViT’s global attention design, which has a quadratic
complexity with respect to the input size. This might be
acceptable for ImageNet classification, but quickly becomes
intractable with higher-resolution inputs.

In this work,
we investigate the architectural distinctions between ConvNets and Transformers and try to identify the confounding
variables when comparing the network performance. Our
research is intended to bridge the gap between the pre-ViT
and post-ViT eras for ConvNets, as well as to test the limits
of what a pure ConvNet can achieve.

Our exploration is directed
by a key question: How do design decisions in Transformers
impact ConvNets’ performance?
We discover several key
components that contribute to the performance difference
along the way. As a result, we propose a family of pure
ConvNets dubbed ConvNeXt. We evaluate ConvNeXts on a
variety of vision tasks such as ImageNet classification [15],
object detection/segmentation on COCO [41], and semantic
segmentation on ADE20K [87].

### Modernizing a ConvNet: a Roadmap
By itself, this enhanced training recipe increased the performance of the ResNet-50 model from 76.1% [1] to 78.8%
(+2.7%), implying that a significant portion of the performance difference between traditional ConvNets and vision
Transformers may be due to the training techniques.

 The accuracy has changed from 79.4% to
79.5%. This suggests that the stem cell in a ResNet may be
substituted with a simpler “patchify” layer à la ViT which
will result in similar performance.

### Empirical Evaluations on ImageNet
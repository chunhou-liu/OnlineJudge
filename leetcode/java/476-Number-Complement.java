class Solution {
    public int findComplement(int num) {
        int shift = 0;
        for(shift=0;shift<32 && (num & 0x80000000)==0;++shift)num << 1;
        return (~num) >>> shift;
    }
}
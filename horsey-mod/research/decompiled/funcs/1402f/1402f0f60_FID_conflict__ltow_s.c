// Address: 0x1402f0f60
// Ghidra name: FID_conflict:_ltow_s
// ============ 0x1402f0f60 FID_conflict:_ltow_s (size=32) ============


/* Library Function - Multiple Matches With Different Base Names

    _itow_s

    _ltow_s

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



errno_t __cdecl FID_conflict__ltow_s(long _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix)



{

  bool bVar1;

  int iVar2;

  

  bVar1 = false;

  if ((_Radix == 10) && (_Val < 0)) {

    bVar1 = true;

  }

  iVar2 = common_xtox_s<unsigned_long,wchar_t>(_Val,_DstBuf,_SizeInWords,_Radix,bVar1);

  return iVar2;

}





// Address: 0x1402de5f4
// Ghidra name: memcpy_s
// ============ 0x1402de5f4 memcpy_s (size=135) ============


/* Library Function - Single Match

    memcpy_s

   

   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */



errno_t __cdecl memcpy_s(void *_Dst,rsize_t _DstSize,void *_Src,rsize_t _MaxCount)



{

  errno_t *peVar1;

  errno_t eVar2;

  

  if (_MaxCount == 0) {

LAB_1402de611:

    eVar2 = 0;

  }

  else {

    if (_Dst == (void *)0x0) {

LAB_1402de61a:

      peVar1 = (errno_t *)FUN_1402e68b0();

      eVar2 = 0x16;

    }

    else {

      if ((_Src != (void *)0x0) && (_MaxCount <= _DstSize)) {

        FUN_1402f8e20(_Dst,_Src,_MaxCount);

        goto LAB_1402de611;

      }

      FUN_1402f94c0(_Dst,0,_DstSize);

      if (_Src == (void *)0x0) goto LAB_1402de61a;

      if (_MaxCount <= _DstSize) {

        return 0x16;

      }

      peVar1 = (errno_t *)FUN_1402e68b0();

      eVar2 = 0x22;

    }

    *peVar1 = eVar2;

    FUN_1402cd454();

  }

  return eVar2;

}





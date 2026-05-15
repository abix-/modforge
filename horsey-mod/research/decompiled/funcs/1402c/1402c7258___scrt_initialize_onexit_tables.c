// Address: 0x1402c7258
// Ghidra name: __scrt_initialize_onexit_tables
// ============ 0x1402c7258 __scrt_initialize_onexit_tables (size=139) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* Library Function - Single Match

    __scrt_initialize_onexit_tables

   

   Library: Visual Studio 2019 Release */



undefined8 __scrt_initialize_onexit_tables(uint param_1)



{

  code *pcVar1;

  int iVar2;

  undefined8 uVar3;

  

  if (DAT_1403fe639 == '\0') {

    if (1 < param_1) {

      FUN_1402c7c38(5);

      pcVar1 = (code *)swi(3);

      uVar3 = (*pcVar1)();

      return uVar3;

    }

    iVar2 = __scrt_is_ucrt_dll_in_use();

    if ((iVar2 == 0) || (param_1 != 0)) {

      DAT_1403fe640 = _DAT_14033ad60;

      uRam00000001403fe648 = _UNK_14033ad68;

      _DAT_1403fe650 = 0xffffffffffffffff;

      _DAT_1403fe658 = _DAT_14033ad60;

      uRam00000001403fe660 = _UNK_14033ad68;

      _DAT_1403fe668 = 0xffffffffffffffff;

    }

    else {

      iVar2 = _initialize_onexit_table(&DAT_1403fe640);

      if ((iVar2 != 0) || (iVar2 = _initialize_onexit_table(&DAT_1403fe658), iVar2 != 0)) {

        return 0;

      }

    }

    DAT_1403fe639 = '\x01';

  }

  return 1;

}





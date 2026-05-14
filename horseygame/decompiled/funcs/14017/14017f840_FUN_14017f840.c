// Address: 0x14017f840
// Ghidra name: FUN_14017f840
// ============ 0x14017f840 FUN_14017f840 (size=162) ============


/* WARNING: Removing unreachable block (ram,0x00014017f8d1) */

/* WARNING: Removing unreachable block (ram,0x00014017f8bf) */



uint FUN_14017f840(void)



{

  longlong lVar1;

  int iVar2;

  char *_Str1;

  

  _Str1 = (char *)FUN_14017fb80();

  iVar2 = strcmp(_Str1,"GenuineIntel");

  if (((iVar2 != 0) && (iVar2 = strcmp(_Str1,"CentaurHauls"), iVar2 != 0)) &&

     (iVar2 = strcmp(_Str1,"  Shanghai  "), iVar2 != 0)) {

    iVar2 = strcmp(_Str1,"AuthenticAMD");

    if ((iVar2 != 0) && (iVar2 = strcmp(_Str1,"HygonGenuine"), iVar2 != 0)) {

      return 0x80;

    }

    lVar1 = cpuid(0x80000005);

    return *(uint *)(lVar1 + 0xc) & 0xff;

  }

  lVar1 = cpuid_Version_info(1);

  return (*(int *)(lVar1 + 4) >> 8 & 0xffU) << 3;

}





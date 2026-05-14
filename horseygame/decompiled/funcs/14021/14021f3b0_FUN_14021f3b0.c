// Address: 0x14021f3b0
// Ghidra name: FUN_14021f3b0
// ============ 0x14021f3b0 FUN_14021f3b0 (size=161) ============


undefined1 FUN_14021f3b0(undefined8 param_1,char *param_2)



{

  short sVar1;

  short *psVar2;

  undefined1 uVar3;

  size_t sVar4;

  short *psVar5;

  char *_Str;

  longlong lVar6;

  

  _Str = "";

  if (param_2 != (char *)0x0) {

    _Str = param_2;

  }

  sVar4 = strlen(_Str);

  psVar5 = (short *)FUN_140197820("UTF-16LE",&DAT_14039c6f0,_Str,sVar4 + 1);

  if (psVar5 != (short *)0x0) {

    lVar6 = 0;

    sVar1 = *psVar5;

    psVar2 = psVar5;

    while (sVar1 != 0) {

      lVar6 = lVar6 + 1;

      psVar2 = psVar2 + 1;

      sVar1 = *psVar2;

    }

    uVar3 = FUN_14021f290(param_1,psVar5,lVar6 * 2 + 2);

    FUN_1401841e0(psVar5);

    return uVar3;

  }

  return 0;

}





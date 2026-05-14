// Address: 0x1400c6bd0
// Ghidra name: FUN_1400c6bd0
// ============ 0x1400c6bd0 FUN_1400c6bd0 (size=288) ============


/* WARNING: Removing unreachable block (ram,0x0001400c6c40) */

/* WARNING: Removing unreachable block (ram,0x0001400c6c91) */



undefined8 * FUN_1400c6bd0(undefined8 *param_1,float param_2)



{

  ulonglong uVar1;

  ulonglong uVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  fVar5 = (float)((uint)param_2 ^ DAT_14039cac0);

  do {

    uVar1 = DAT_1403da740 << 0xd ^ DAT_1403da740;

    uVar1 = uVar1 >> 7 ^ uVar1;

    uVar1 = uVar1 << 0x11 ^ uVar1;

    uVar2 = uVar1 << 0xd ^ uVar1;

    uVar2 = uVar2 >> 7 ^ uVar2;

    DAT_1403da740 = uVar2 << 0x11 ^ uVar2;

    fVar4 = (float)(uVar1 & 0xffff) * DAT_1403053bc * (param_2 - fVar5) + fVar5;

    fVar3 = (float)(DAT_1403da740 & 0xffff) * DAT_1403053bc * (param_2 - fVar5) + fVar5;

  } while (param_2 * param_2 <= fVar3 * fVar3 + fVar4 * fVar4);

  *param_1 = CONCAT44(fVar4,fVar3);

  return param_1;

}





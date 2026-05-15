// Address: 0x1400e4480
// Ghidra name: FUN_1400e4480
// ============ 0x1400e4480 FUN_1400e4480 (size=278) ============


/* WARNING: Removing unreachable block (ram,0x0001400e44dd) */

/* WARNING: Removing unreachable block (ram,0x0001400e451f) */

/* WARNING: Removing unreachable block (ram,0x0001400e44f3) */

/* WARNING: Removing unreachable block (ram,0x0001400e453e) */



undefined8 FUN_1400e4480(byte *param_1,int param_2)



{

  byte bVar1;

  uint uVar2;

  char *pcVar3;

  byte *pbVar4;

  

  pcVar3 = "#?RADIANCE\n";

  pbVar4 = param_1 + param_2;

  while( true ) {

    uVar2 = 0;

    if (param_1 < pbVar4) {

      bVar1 = *param_1;

      param_1 = param_1 + 1;

      uVar2 = (uint)bVar1;

    }

    if (uVar2 != (int)*pcVar3) break;

    pcVar3 = pcVar3 + 1;

    if (*pcVar3 == '\0') {

      return 1;

    }

  }

  return 0;

}





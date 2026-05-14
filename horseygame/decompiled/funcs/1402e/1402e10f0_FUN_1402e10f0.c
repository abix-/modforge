// Address: 0x1402e10f0
// Ghidra name: FUN_1402e10f0
// ============ 0x1402e10f0 FUN_1402e10f0 (size=154) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



byte * FUN_1402e10f0(byte *param_1,byte *param_2)



{

  byte *pbVar1;

  byte bVar2;

  byte local_38 [56];

  

  bVar2 = *param_2;

  local_38[0] = 0;

  local_38[1] = 0;

  local_38[2] = 0;

  local_38[3] = 0;

  local_38[4] = 0;

  local_38[5] = 0;

  local_38[6] = 0;

  local_38[7] = 0;

  local_38[8] = 0;

  local_38[9] = 0;

  local_38[10] = 0;

  local_38[0xb] = 0;

  local_38[0xc] = 0;

  local_38[0xd] = 0;

  local_38[0xe] = 0;

  local_38[0xf] = 0;

  local_38[0x10] = 0;

  local_38[0x11] = 0;

  local_38[0x12] = 0;

  local_38[0x13] = 0;

  local_38[0x14] = 0;

  local_38[0x15] = 0;

  local_38[0x16] = 0;

  local_38[0x17] = 0;

  local_38[0x18] = 0;

  local_38[0x19] = 0;

  local_38[0x1a] = 0;

  local_38[0x1b] = 0;

  local_38[0x1c] = 0;

  local_38[0x1d] = 0;

  local_38[0x1e] = 0;

  local_38[0x1f] = 0;

  while (bVar2 != 0) {

    local_38[(longlong)(int)(uint)bVar2 >> 3] =

         local_38[(longlong)(int)(uint)bVar2 >> 3] | '\x01' << (bVar2 & 7);

    pbVar1 = param_2 + 1;

    param_2 = param_2 + 1;

    bVar2 = *pbVar1;

  }

  bVar2 = *param_1;

  while( true ) {

    if (bVar2 == 0) {

      return (byte *)0x0;

    }

    if ((local_38[bVar2 >> 3] >> (bVar2 & 7) & 1) != 0) break;

    bVar2 = param_1[1];

    param_1 = param_1 + 1;

  }

  return param_1;

}






/**
 * libdiskimage
 * VDI Block Storage
 * (C) 2012 by Marc S. Ressl (mressl@umich.edu)
 * Released under the GPL
 *
 * Accesses a VDI block storage
 */

#ifndef DIVDIBLOCKSTORAGE_H
#define DIVDIBLOCKSTORAGE_H

#include "DICommon.h"
#include "DIBackingStore.h"
#include "DIBlockStorage.h"

typedef enum
{
    DI_VDI_DYNAMIC = 1,
    DI_VDI_STATIC,
} DIVDIFormat;

class DIVDIBlockStorage : public DIBlockStorage
{
public:
    DIVDIBlockStorage();
    
    bool open(DIBackingStore *backingStore);
    void close();
    
    bool isWriteEnabled();
    DIInt getBlockNum();
    string getFormatLabel();
    
    bool readBlocks(DIInt index, DIChar *buf, DIInt num);
    bool writeBlocks(DIInt index, const DIChar *buf, DIInt num);
    
private:
    DIBackingStore *backingStore;
    
    DIInt type;
    DIInt offsetBlocks;
    DIInt offsetData;
    
    DIInt cylinders;
    DIInt heads;
    DIInt sectors;
    
    DILong diskSize;
    DIInt blockSize;
    DIInt blockExtraData;
    DIInt blocksInHDD;
    DIInt blocksAllocated;
};

#endif

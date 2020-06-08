from enum import Enum


class VehicleSize(Enum):

    SMALL = 1
    COMPACT = 2
    LARGE = 3


class Vehicle:
    def __init__(self, sizeOfVehicle, regNo):
        self.sizeOfVehicle = sizeOfVehicle
        self.regNo = regNo
        self.parkingLot = ParkingLot.getInstance()

    def findSlot(self):
        if self.sizeOfVehicle == VehicleSize.SMALL:
            slots = self.parkingLot.getSmallSlots()
        if self.sizeOfVehicle == VehicleSize.COMPACT:
            slots = self.parkingLot.getCompactSlot()
        if self.sizeOfVehicle == VehicleSize.LARGE:
            slots = self.parkingLot.getLargeSlot()
        if len(slots) > 0:
            return slots.pop()
        return None
   
    def park(self):
       slot = self.findSlot()
       if slot is not None:
           slot.occupy(self)
           self.parkingLot.occupiedSlots[self.regNo] = slot
    
    def leave(self):
        slot = self.parkingLot.occupiedSlots.pop(self.regNo)
        slot.release()

        if self.sizeOfVehicle == VehicleSize.SMALL:
            slots = self.parkingLot.getSmallSlots()
        if self.sizeOfVehicle == VehicleSize.COMPACT:
            slots = self.parkingLot.getCompactSlot()
        if self.sizeOfVehicle == VehicleSize.LARGE:
            slots = self.parkingLot.getLargeSlot()

        slots.append(slot)


class Slot:

    def __init__(self,slotId,size):
        self.slotId = slotId
        self.size = size
        self.vehicle = None
        self.available = True

    def occupy(self, vehicle):
        self.vehicle = vehicle
        self.available = False

    def release(self):
        self.vehicle = None
        self.available = True

class Bike(Vehicle):

    def __init__(self, regNo):
        super(Bike, self).__init__(VehicleSize.SMALL, regNo)


class Car(Vehicle):

    def __init__(self, regNo):
        super(Car, self).__init__(VehicleSize.COMPACT, regNo)


class Bus(Vehicle):

    def __init__(self, regNo):
        super(Bus, self).__init__(VehicleSize.LARGE, regNo)


class ParkingLot:
    _numberOfSmallSlots = 10
    _numberOfCompactSlots = 10
    _numberOfLargeSlots = 10
    parkingLot = None

    def __init__(self):
        self.occupiedSlots = {}
        self._smallSlotStatus = []
        self._compactSlotStatus = []
        self._largeSlotStatus = []
        
        for slotId in range(1, ParkingLot._numberOfSmallSlots+1):
            self._smallSlotStatus.append(Slot(slotId, VehicleSize.SMALL))

        for slotId in range(1, ParkingLot._numberOfCompactSlots+1):
            self._compactSlotStatus.append(Slot(slotId, VehicleSize.COMPACT))

        for slotId in range(1, ParkingLot._numberOfLargeSlots+1):
            self._largeSlotStatus.append(Slot(slotId, VehicleSize.LARGE))

    def getSmallSlots(self):
        return self._smallSlotStatus

    def getCompactSlot(self):
        return self._compactSlotStatus

    def getLargeSlot(self):
        return self._largeSlotStatus

    @staticmethod
    def printParkedVehicles():
        for regNo in ParkingLot.parkingLot.occupiedSlots.keys():
            print(regNo)
    
    @staticmethod
    def printAvialableSmallSlots():
        print("Number of available small slots : ", len(ParkingLot.parkingLot._smallSlotStatus))
    
    @staticmethod
    def getInstance():
        if ParkingLot.parkingLot is None:
            ParkingLot.parkingLot = ParkingLot()
        
        return ParkingLot.parkingLot

if __name__ == '__main__':

    bike1 = Bike('abc123')
    bike2 = Bike('abc121')
    car1 = Car('abc124')
    bus1 = Bus('abc126')
    bike1.park()
    bike2.park()
    bus1.park()
    car1.park()
    ParkingLot.printParkedVehicles()
    bike1.leave()
    print("-"*50)
    ParkingLot.printParkedVehicles()
    ParkingLot.printAvialableSmallSlots()

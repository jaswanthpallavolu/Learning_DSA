### Parking Lot

> Design a parking lot system where vehicle enters the parking lot and gets the available parking slot suitable for the vehicle type.
> later vehicle exists after that the occupied parking slot will be released and parking fee calculated

#### Requiements

- Vehicle entry
- Slot allocation
- Vehicle exits
- Parking fee
- Slot Availability

> assumption:
> one parking lot, fixed no of slots, don't handle reservation,

### Core entities

- Vehicle
- ParkingLot
- ParkingSlot
- ParkingTicket

Vehicle

- licenseNumber
- type

VehicleType

- MOTORCYCLE
- CAR
- TRUCK

ParkingSlot

- id
- type
- status
- parkedVehicle

SlotType

- MOTORCYCLE
- CAR
- TRUCK

ParkingTicket

- ticketId
- vehicle
- slot
- entryTime
- exitTime

ParkingLot

- park(vehicle)
- exit(ticketId)

SlotManager

- findAvailableSlot(vehicleType)
- occupySlot(vehicle, slot)
- releaseSlot(slotId)

PricingStrategy

- calculateFee(ticket)

TicketManager

- getTicket(ticketId)
- createTicket(vehicle, slot, enterTime)
- removeTicket(ticketId)

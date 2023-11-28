import sys
import pybind as pb

pb.start()
for cnt in range(10000):
	pb.access()
pb.end()

elapsed = pb.get_elapsed_time()
print('elapsed time: ', elapsed)
print('elapsed time per access: ', pb.get_elapsed_time_per_access())

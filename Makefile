dev:
	$(MAKE) -C producer
	$(MAKE) -C consumer
	$(MAKE) -C scullbuffer

clean:
	$(MAKE) -C consumer clean
	$(MAKE) -C producer clean
	$(MAKE) -C scullpipe clean
	rm -r *_log